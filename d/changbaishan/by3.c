
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "��ɲӪ��");
	set("long",
"��������������ܵľ���������˲������ţ���ǰ��ľ�Ӫ������ͬ����Ƥ���ھ��Σ�\n"
"�������ںڸ���ʯ���ϣ���Ϊ��Ե˫����ͼ������������������ȣ�����������ë��Ƥ�̳�\n"
"����ȷʵ�и���Ӫ�ʵ�ζ����\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"by2",


]));

        set("objects", ([
               "/kungfu/class/hu/wgj1" : 1,
               "/kungfu/class/hu/wgj2" : 1,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
        