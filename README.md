# ESP8266-Cc1101

## 📡 ESP8266 & CC1101 ile 433MHz RF Alıcı & Verici Kontrolü
Bu proje, **ESP8266 ve CC1101 modülü** kullanarak ** RF sinyallerini alıp göndermenizi** sağlar. **Önceki "ESP8266-Arduino-433MHz" projesinin CC1101 modüllü versiyonudur**. **SmartRC-CC1101-Driver-Lib** ve **RCSwitch** kütüphaneleri ile **kablosuz haberleşme** yapmak mümkündür.

---

## 🚀 Özellikler
✅ **ESP8266 Desteği**
✅ **CC1101 RF Alıcı & Verici Kullanımı**
✅ **Seri Port Üzerinden Komut Gönderme**
✅ **Alıcı & Verici Modları Arasında Geçiş**
✅ **Kolay Entegrasyon & Kullanım**

---

## 🔧 Donanım Gereksinimleri
- **ESP8266 (NodeMCU, Wemos D1 Mini vb.)**
- **CC1101 Modülü**
- **Bağlantı kabloları**

---

## 🔌 CC1101 Pin Bağlantıları (ESP8266 İçin)
| **CC1101 Pin** | **ESP8266 Pin** |
|--------------|--------------|
| VCC         | 3.3V         |
| GND         | GND          |
| SCK         | D5 (GPIO14)  |
| MISO        | D6 (GPIO12)  |
| MOSI        | D7 (GPIO13)  |
| CSN         | D8 (GPIO15)  |
| GDO0        | D2 (GPIO4)   |
| GDO2        | D1 (GPIO5)   |

📌 **CC1101 modülü 5V ile çalışmaz, mutlaka 3.3V besleme yapılmalıdır!**

---

## 🛠️ Kütüphane Kurulumu
Arduino IDE veya PlatformIO üzerinde **ELECHOUSE_CC1101_SRC_DRV** ve **RCSwitch** kütüphanelerini yüklemek için:
1. **Arduino IDE** için:
   - "Sketch" -> "Include Library" -> "Manage Libraries" menüsüne girin.
   - **"SmartRC-CC1101-Driver-Lib"** ve **"RCSwitch"** kütüphanelerini yükleyin.

2. **PlatformIO** için:
   ```ini
   lib_deps = 
     Elechouse/CC1101@^1.0.0
     sui77/RCSwitch@^2.6.4
   ```

---

## 🎮 Kullanım
1. **Cihazı USB ile bağlayın ve kodu yükleyin.**
2. **Seri Monitörü (Baud: 9600) açın.**
3. **Komutlar:**
   - **'r'** tuşuna basarsanız **alıcı modu** aktif olur.
   - **'t'** tuşuna basarsanız **verici modu** aktif olur ve RF kodu gönderilir.

---

## 📜 Lisans
Bu proje, **GNU GPL-2.0** lisansı altında yayımlanmaktadır. **ELECHOUSE_CC1101_SRC_DRV** kütüphanesi **Little Satan tarafından modlanmış ELECHOUSE CC1101 kütüphanesine dayanan SmartRC-CC1101-Driver-Lib** versiyonudur. **RCSwitch** kütüphanesi ise **GPL-2.0 lisansı** ile dağıtılmaktadır.

**SmartRC-CC1101-Driver-Lib Kütüphanesi:** [https://github.com/LSatan/SmartRC-CC1101-Driver-Lib](https://github.com/LSatan/SmartRC-CC1101-Driver-Lib)

**RCSwitch Kütüphanesi:** [https://github.com/sui77/rc-switch](https://github.com/sui77/rc-switch)

---

## 📩 Katkıda Bulunma
Projeye katkıda bulunmak için **pull request gönderebilir** veya **hata bildirimi** yapabilirsiniz. Geri bildirimleriniz değerlidir! 😊

