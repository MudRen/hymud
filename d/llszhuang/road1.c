inherit ROOM;
void create()
{
        set("short", "ɽ��С·");
        set("long",
"����ɽɫ������������·����������̦޺������������е���������\n"
"��ɽ��ɣ��Ĳ�û����·�߹�ľ������ÿ�Թ�ľ�϶������˳�������ľ\n"
"�̣�ľ���ϻ����Ÿ�����ɫ�Ĳ�����\n"
);
        set("exits", ([
  "west" : __DIR__"road2",
  "eastdown" : __DIR__"road",
]));
        set("outdoors", "llszhuang");
        setup();
}

