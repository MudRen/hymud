
// Room: /u/cloud/shijie2.c


inherit ROOM;

void create()
{
        set("coor",({4100,-1050,0}));
	set("short", "ʯ��");
        set("long",
"��������һ����ʯ���̳ɵ���С����,���һ��СϪ,����һ��ɽ��,ǰ���ֺ���һ��ɽ��,\n"
"�������ۻ���,��Ҫ��Ϣһ���ˡ�������һ������ʯ��,�㲻�ɵ�̾�˿�����\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shijie3",
  "southwest" : __DIR__"shijie1",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

