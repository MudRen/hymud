 // Room: /d/oldpine/tree1.c
inherit ROOM; 
void create()
{
        set("short", "������");
        set("long", @LONG
���������ʸ���һ������������ϣ���������Ժ������������
�µ�һ�ж������������˷������ƺ��Ǹ���͵�����������ĺõط���
LONG
        );
        set("objects", ([
                __DIR__"npc/spy":1 ,
                __DIR__"npc/maque" : 2,
        ]) ); 
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tanghuai",
])); 
        set("coor/x",30);
        set("coor/y",2000);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}  
