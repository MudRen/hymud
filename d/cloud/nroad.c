
// Room: /u/cloud/dragonhill/nroad.c

inherit ROOM;

void create()
{
        set("coor",({0,4550,10}));
	set("short", "����·");
        set("long",
"��������Զ��ͨ�������ıؾ�֮���߾�����Զ�ǣ�����ͨ�������ڡ����ȹٸ����ڴ�����\n"
"��·�����������ε������ޣ������������ϳ���ǿ�˳�û��ֻ�����ա���˵����·���ɹ�\n"
"�����˺ܶ࣬·���ѱ��ȵú�ƽ�ˡ�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/ny/nroad6",
  "northeast" : "/d/xueting/sgate",
  "southeast" : __DIR__"nhillfoot",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}
