 inherit ROOM;
void create()
{
        set("short", "���ɸ���");
        set("long", @LONG
���Ǻ��ɱ������ڻ�̫ӭ���Ķ����������������õ�Ӻ�ٵ��š�
�򶫺��������Ǿ����޼����Ļ�԰��¥�����Ǵ��ھ޴��˯����
ż���м������дӶ���԰�ﴫ����
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"east_garden",
  "south" : __DIR__"south_garden",
  "westup" : __DIR__"bedroom",
]));
                set("objects", ([
                __DIR__"npc/cleangirl" : 1,
        ]) ); 
        set("coor/x",130);
        set("coor/y",190);
        set("coor/z",40);
        setup();
}  
