 inherit ROOM;
void create()
{
        set("short", "�ڰ�����");
        set("long", @LONG
��������ƺ����Ӻڰ������䣬��͸��Ũ���Ѫ����ζ��
��Χ�Ŀ����ƺ����Ѿ����������������ص�����͸����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
         "east" : __DIR__"zoulang1",
         "west" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/dizi": 1,
                        ]) ); 
        set("coor/x",3280);
        set("coor/y",30);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
}      
