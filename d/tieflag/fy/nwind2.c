inherit ROOM;
void midnight_event();
void sunrise_event(); 
void create()
{
        set("short", "�����");
        set("long", @LONG
�����Ƿ��ƹ㳡�ı��ߣ��������������Կ���Զ�����ʵĳ�ǽ�����ֵĽֵ���
���������µĻ������˿˿֬�۵������������ǴӴ�ֶ����Ʈ�㻨�굴�������ģ�
��Ũ���֬����Ϣ�������������֬������ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"nwind1",
                "north" : __DIR__"nwind3",
                "east" : __DIR__"pxhdian",
                "west" : __DIR__"qcyzdian",
        ]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",0);
        setup();
//        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
