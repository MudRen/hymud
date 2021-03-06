 inherit ROOM;
void create()
{
        set("short", "元君庙");
        set("long", @LONG
元君庙位于独足盘东北，绝壁环抱，北崖上大书“天空山”，俗称玉女山。
其山巅平坦，传尧曾登此，故又名尧观台。　庙周围有明人王之纲“玉女修
真处”、吴同春“岱岳奥区”、吴献台“丛翠”及清人宋思仁“石坞云间”等题刻。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"shiba",
  "west" : __DIR__"shanfeng",
  "north" : __DIR__"houshi",
  "east" : __DIR__"bixia",
])); 
        set("item_desc", ([
                "石刻": "               
                阶              门
                崇              辟
                万              九
                级              霄
                俯              仰
                临              步
                千              三
                嶂              天
                奇              胜
                观              迹
                 。              ，                     
"        ]) );
        set("objects", ([
        __DIR__"npc/pettrainer" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2390);
        set("coor/z",120);
        setup();
        replace_program(ROOM);
}   
