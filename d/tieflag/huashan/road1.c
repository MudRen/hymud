 inherit ROOM;
void midnight_event();
void sunrise_event();
void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵĻ�Ұ�أ�ƽ̹�ĵ�������һ���������߼ʣ������ϲ�����ɳʯ
���飬һ������·��ֱ������������·�Եĵ�������һ�ԴԵĹ�ľ�Ӳݣ��Һ�ɫ��
ҶƬ����һ�ֳ������Ƶĸо���
LONG
        );
    set("exits", ([ 
                "west" : __DIR__"road2",
        "southeast" : "/d/huashan/yunupath1",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-550);
    set("coor/y",-10);
    set("coor/z",0);
    //NATURE_D->add_day_event(20, 2, this_object(), (: midnight_event :)); 
        setup();
} 
