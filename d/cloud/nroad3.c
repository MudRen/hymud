
// Room: /u/cloud/nroad3.c


inherit ROOM;

void create()
{
        set("coor",({4000,-1200,0}));
	set("short", "ɽ·");
        set("long",
"������������һ��ɽ���С·��,С·�����������де���ľ�Ͳݴԣ�ż�����м���Ұ��(fl\n"
"ower)�����ּ䴫�������������������һƬ���֣�����һ���Ĳ����Դ��\n"
);
        set("item_desc", ([/*sizeof() == 1 */
             "flower" : "����һ��ۺ�ɫ�Ļ�,�����ס�����ժ����,����,
���Ҫ��ס:·�ߵ�Ұ���ɲ���!\n",
            ]));
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad4",
            "westup" : __DIR__"wood",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

