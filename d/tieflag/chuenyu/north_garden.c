 inherit ROOM;
void create()
{
        set("short", "����԰");
        set("long", @LONG
��վ�ں��ɳǱ��Ķ���԰���԰�ﳤ���˸�ʽ�����滨��ݡ�
��ͨ�����·��һ���ʯ(rock)������������������ΰ�ĺ��ɸ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west_blackge",
]));
                set("objects", ([
                __DIR__"npc/smallgardener" : 2,
        ]) ); 
        set("item_desc", ([
  "rock" : "����һ��ǧ���ʯ����ס��ͨ�����·��\n",
]));  
        set("outdoors", "chuenyu"); 
        set("coor/x",110);
        set("coor/y",200);
        set("coor/z",40);
        setup();
}      
