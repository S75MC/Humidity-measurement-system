import tkinter as tk
from tkinter import ttk
import serial
import threading

class IrrigationUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Smart Irrigation Control")
        
        # إعدادات الاتصال
        self.arduino = None
        self.serial_port = 'COM3'
        self.baud_rate = 9600
        
        # متغيرات النظام
        self.moisture_percent = 0
        self.is_pump_on = False
        
        # بناء الواجهة
        self.create_widgets()
        
        # بدء الثريدات
        self.running = True
        self.start_serial_thread()

    def create_widgets(self):
        # إطار المؤشرات
        status_frame = ttk.LabelFrame(self.root, text="حالة النظام")
        status_frame.grid(row=0, column=0, padx=10, pady=5, sticky="ew")
        
        # شريط تقدم الرطوبة
        self.moisture_bar = ttk.Progressbar(status_frame, orient='horizontal', length=200)
        self.moisture_bar.grid(row=0, column=0, padx=5, pady=5)
        
        # عرض النسبة المئوية
        self.percent_label = ttk.Label(status_frame, text="0%", font=('Arial', 14))
        self.percent_label.grid(row=0, column=1, padx=5)
        
        # مؤشر حالة المضخة
        self.pump_frame = ttk.Frame(status_frame)
        self.pump_frame.grid(row=1, column=0, columnspan=2, pady=5)
        
        self.pump_status = ttk.Label(self.pump_frame, text="حالة المضخة:")
        self.pump_status.pack(side=tk.LEFT)
        
        self.pump_indicator = tk.Canvas(self.pump_frame, width=30, height=30)
        self.pump_indicator.pack(side=tk.LEFT)
        self.draw_indicator(self.pump_indicator, "gray")
        
        # أزرار التحكم
        control_frame = ttk.LabelFrame(self.root, text="التحكم")
        control_frame.grid(row=1, column=0, padx=10, pady=5, sticky="ew")
        
        self.btn_auto = ttk.Button(control_frame, text="وضع تلقائي", command=self.set_auto_mode)
        self.btn_auto.pack(side=tk.LEFT, padx=5)
        
        self.btn_manual_on = ttk.Button(control_frame, text="تشغيل يدوي", command=self.manual_pump_on)
        self.btn_manual_on.pack(side=tk.LEFT, padx=5)
        
        self.btn_manual_off = ttk.Button(control_frame, text="إيقاف يدوي", command=self.manual_pump_off)
        self.btn_manual_off.pack(side=tk.LEFT, padx=5)
        
        # تحديث الواجهة
        self.update_ui()

    def draw_indicator(self, canvas, color):
        canvas.delete("all")
        canvas.create_oval(5, 5, 25, 25, fill=color, outline="black")

    def update_ui(self):
        # تحديث شريط التقدم والنسبة
        self.moisture_bar['value'] = self.moisture_percent
        self.percent_label.config(text=f"{int(self.moisture_percent)}%")
        
        # تحديث مؤشر المضخة
        pump_color = "blue" if self.is_pump_on else "gray"
        self.draw_indicator(self.pump_indicator, pump_color)
        
        # إعادة الجدولة
        self.root.after(300, self.update_ui)

    def start_serial_thread(self):
        def serial_reader():
            try:
                self.arduino = serial.Serial(self.serial_port, self.baud_rate)
                while self.running:
                    if self.arduino.in_waiting > 0:
                        data = self.arduino.readline().decode().strip()
                        self.process_data(data)
            except Exception as e:
                print("خطأ في الاتصال:", str(e))
        
        threading.Thread(target=serial_reader, daemon=True).start()

    def process_data(self, data):
        if data.startswith("STATUS"):
            parts = data.split(':')
            if len(parts) == 3:
                self.moisture_percent = float(parts[1])
                self.is_pump_on = (parts[2] == "ON")

    def set_auto_mode(self):
        if self.arduino:
            self.arduino.write(b'AUTO\n')

    def manual_pump_on(self):
        if self.arduino:
            self.arduino.write(b'MANUAL_ON\n')

    def manual_pump_off(self):
        if self.arduino:
            self.arduino.write(b'MANUAL_OFF\n')

    def on_close(self):
        self.running = False
        if self.arduino:
            self.arduino.close()
        self.root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    app = IrrigationUI(root)
    root.protocol("WM_DELETE_WINDOW", app.on_close)
    root.mainloop()