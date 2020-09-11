from flask import Blueprint, request, jsonify, render_template
from flaskr.db import get_db

bp = Blueprint('frontend', __name__, url_prefix='/connected_garden')

@bp.route("/")
def index():
    db = get_db()
    measures = db.execute("SELECT datetime(timestamp, 'unixepoch', 'localtime') AS readable_timestamp, temperature, humidity, estimatedTimestamp AS estimated_timestamp FROM measure ORDER BY timestamp DESC").fetchall()
    return render_template("measurements.html", measures=measures)

