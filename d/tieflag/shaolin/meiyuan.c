 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", " ÷԰");
        set("long", @LONG
 ��Ķ������԰�ӣ�������÷����԰��÷֦��б�����������¡� 
 �����徻���࣬�ƺ�������������ɨ�� 
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"banruo",
  "west" : __DIR__"shan",
]));
    set("outdoors", "shaolinfy");
    set("coor/x",-215);
        set("coor/y",380);
        set("coor/z",70);
        setup();
} 
void init()
{
        object me,meizhi;
        if (!random(50))
        {
                if(interactive(me = this_player()) && !me->is_fighting() && userp(me))
                {
                        if (!present("meizhi",this_object()))
                        {
                                meizhi = new(__DIR__"obj/meizhi");
                                meizhi->move(this_object());
                        }
                }
        }
}   
