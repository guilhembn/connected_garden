from flask import Blueprint, request, jsonify, render_template
from flaskr.db import get_db
import json
import time

bp = Blueprint('frontend', __name__, url_prefix='/connected_garden')

@bp.route("/")
def index():
    db = get_db()
    measures = db.execute("SELECT datetime(timestamp, 'unixepoch', 'localtime') AS readable_timestamp, temperature, humidity, estimatedTimestamp AS estimated_timestamp FROM measure ORDER BY timestamp DESC").fetchall()
    return render_template("measurements.html", measures=measures)


@bp.route("/data", methods=["GET"])
def plot():
    if request.method == "GET":
        time_range = request.args.get('range', "all", type=str)
        db = get_db()
        min_time = 0
        if time_range == "day":
            min_time = time.time() - 24*3600
        elif time_range == "all":
            min_time = 0
        measures = db.execute("SELECT timestamp, temperature, humidity, estimatedTimestamp AS estimated_timestamp FROM measure WHERE timestamp >= ? ORDER BY timestamp DESC", (min_time,)).fetchall()
        return jsonify({"data": [{"timestamp": m["timestamp"], "temperature": m["temperature"], "humidity": m["humidity"]} for m in measures]})
    return jsonify({"data": []})



