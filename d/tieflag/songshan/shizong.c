 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石淙会饮");
        set("long", @LONG
石淙河发源九龙潭，蜿蜒群山中，形成“水营山阵”的“天中胜
景”，后被武则天看中，大宴群臣于潭南的“水漂石”之上，观赏秋
景，“石淙会饮”即出于此。两岸摩崖则为张易之手书之“秋日宴石
淙序”，由薛曜写来，“骨峰瘦劲，峭疏健朗”经千年而未损，留传
后人，后世观者无不赞叹不绝。顺河而下，便可以到观星台一游。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"zhongyue",
  "southup" : __DIR__"guansing",
]));
        set("outdoors", "songshanfy");
        set("coor/x",-170);
        set("coor/y",100);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
