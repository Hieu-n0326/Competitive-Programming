import sys

from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel
from PySide6.QtCore import Qt


def create_main_window() -> QWidget:
    w = QWidget()
    w.setWindowTitle("Flashcard App")
    w.resize(400, 500)

    layout = QVBoxLayout(w)

    title = QLabel("FLASHCARD APP")
    title.setAlignment(Qt.AlignCenter)
    title.setStyleSheet("font-size:28px; font-weight:bold;")

    btn = QPushButton("Start Study")
    btn.setStyleSheet(
        """
        QPushButton {
            background:#4cd137;
            color:white;
            padding:15px;
            border-radius:20px;
            font-size:16px;
        }
        QPushButton:hover { background:#44bd32; }
        """
    )

    layout.addWidget(title)
    layout.addWidget(btn)

    return w


def main() -> int:
    app = QApplication(sys.argv)
    w = create_main_window()
    w.show()
    return app.exec()


if __name__ == "__main__":
    raise SystemExit(main())
