
````markdown
# Pen-DB 🚀  

A super-lightweight key-value database built from scratch in C++ with:  
- **Persistent storage on disk**  
- **REST API using cpp-httplib**  
- **Single-file HTML frontend**  

---

## Features ✨
- ✅ Persistent key-value store (`data.txt`)
- ✅ REST API endpoints: `/set`, `/get`, `/delete`, `/all`
- ✅ CORS enabled – works with browser frontends
- ✅ Minimal web frontend for managing data
- ✅ Easily extensible for embeddings, vector search, etc.

---

## Quick Start 🛠️

### 1. Clone and build
```bash
git clone <https://github.com/Allen739/pen-db.git>
cd <pen-db>
g++ api.cpp db.cpp -o server -lhttplib -lpthread
./server
````

The API runs on **[http://localhost:8080](http://localhost:8080)**

### 2. Open the frontend

Open `frontend/index.html` in your browser.
You can `SET`, `GET`, `DELETE`, and `VIEW ALL` your data.

---

## API Reference 📡

| Method | Endpoint | Parameters | Description          |
| ------ | -------- | ---------- | -------------------- |
| POST   | /set     | key, value | Set a key-value pair |
| GET    | /get     | key        | Get a single value   |
| POST   | /delete  | key        | Delete a key-value   |
| GET    | /all     | –          | View all stored data |

---

## Roadmap 🗺️

* [ ] Add JSON responses
* [ ] Add a nicer frontend (React/Vue/Next.js)
* [ ] Add vector embeddings & similarity search
* [ ] Authentication / ACLs
* [ ] Dockerfile for easy deploy

---

## Contributing 🤝

PRs welcome!
Fork, branch, code, and submit a pull request.

---

## License 📝

MIT License © 2025 \[Allen739]

````

---

### **How to commit:**

```bash
nano README.md   # paste the above content
git add README.md
git commit -m "Added initial README with build/run instructions"
git push
````

