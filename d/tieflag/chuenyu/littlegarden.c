 inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
�������Ϻ���С��԰����԰���кܶ������Ļ��䡣���Ϻ�
���ǿ�������ά�����Ƶġ��������ǻ����Ĵ�ü��ڣ��кܶ�
���ڼ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"home",
]));
        set("objects", ([
                __DIR__"npc/flowergirl" : 5,
        ]) );
        set("outdoors", "chuenyu");
        set("coor/x",120);
        set("coor/y",150);
        set("coor/z",0);
        setup();
} 
