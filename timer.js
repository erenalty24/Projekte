// Timer-Variablen
let time = 25 * 60;
let isRunning = false;
let timerInterval;

// Timer formatieren (Minuten:Sekunden)
function formatTime(seconds) {
    const minutes = Math.floor(seconds / 60);
    const secs = seconds % 60;
    return `${minutes}:${secs < 10 ? '0' : ''}${secs}`;
}

// Timer-Anzeige aktualisieren
function updateTimerDisplay() {
    document.getElementById('timer').innerText = formatTime(time);
}

// Dark Mode umschalten und speichern
function toggleDarkMode() {
    document.body.classList.toggle("dark-mode");

    // Dark Mode Status in localStorage speichern
    const isDarkMode = document.body.classList.contains("dark-mode");
    localStorage.setItem("darkMode", isDarkMode);
}

// Beim Laden der Seite Dark Mode Status prüfen
window.onload = function () {
    if (localStorage.getItem("darkMode") === "true") {
        document.body.classList.add("dark-mode");
    }
};

// Timer starten oder pausieren
function toggleTimer() {
    const button = document.getElementById('start-btn');

    if (isRunning) {
        clearInterval(timerInterval);
        button.innerText = "Start"; // Button wechselt zu "Start"
    } else {
        timerInterval = setInterval(() => {
            if (time > 0) {
                time--;
                updateTimerDisplay();
            } else {
                clearInterval(timerInterval);
                isRunning = false;
                button.innerText = "Start"; // Button zurücksetzen nach Ablauf
            }
        }, 1000);
        button.innerText = "Pause"; // Button wechselt zu "Pause"
    }
    isRunning = !isRunning;
}

// Modus ändern (Focus, Short Break, Long Break)
function setMode(duration) {
    clearInterval(timerInterval);
    isRunning = false;
    time = duration * 60;
    updateTimerDisplay();
    document.getElementById('start-btn').innerText = "Start"; // Button zurücksetzen
}

// Timer beim Laden direkt aktualisieren
updateTimerDisplay();


// Modal öffnen
function openLoginModal() {
    document.getElementById("loginModal").style.display = "block";
}

// Modal schließen
function closeLoginModal() {
    document.getElementById("loginModal").style.display = "none";
}

// Einfache Login-Funktion
function login() {
    let username = document.getElementById("username").value;
    let password = document.getElementById("password").value;

    if (username === "admin" && password === "1234") {
        alert("Login erfolgreich!");
        closeLoginModal();
    } else {
        alert("Falscher Benutzername oder Passwort!");
    }
}

// Schließen, wenn außerhalb geklickt wird
window.onclick = function(event) {
    let modal = document.getElementById("loginModal");
    if (event.target === modal) {
        modal.style.display = "none";
    }
};

