#include <room.h>
inherit ROOM; 
void create()
{
    seteuid(getuid());
        set("short", "��ʯС��");
        set("long", @LONG
�ƹ������, ��������ǰ����һ��ľ������ߵ����ӡ���������
���Ŵ��������Ĺ���, �ſ��Ϸ�����һ����ɫ�����Ҷ�, ���顺�ؾ�
¥���������֡���������һ��ʯ��(slab)��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast" : __DIR__"stoneroad",
            "north" : __DIR__"book_room1",
]));  
        set("outdoors", "taoguan");
        set("item_desc", ([
            "slab" : "ʯ����д�� : \n\n"
                     "    ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n\n"
           ]) ); 
    set("coor/x",-40);
        set("coor/y",2130);
        set("coor/z",80);
        setup(); 
    reset();
}    
