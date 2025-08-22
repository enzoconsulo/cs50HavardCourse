sqlite> SELECT AVG(energy) from songs
   ...> JOIN artists ON songs.id = artists.id
   ...> WHERE artists.name = "Drake";
+-------------+
| AVG(energy) |
+-------------+
| 0.789       |
+-------------+
