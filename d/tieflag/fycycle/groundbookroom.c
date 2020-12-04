#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ʯ��");
        set("long", @LONG
��һ�߽������ӣ�����һ�ɺ���֮������������������д�����ȫ��ʯ�ƣ���
��Ҳ������ʯ���̣��ٱ��Ϲ���һ����������������һ�����ң�ʯ���Ϸ���һЩ��
��������֮�⣬���оͱ������
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"groundroom",
        ])); 
        set("objects", ([
        __DIR__"obj/endtable" : 1,
                        ]));
    set("indoors", "fengyun");
    set("coor/x",-160);
    set("coor/y",50);
    set("coor/z",0);
        set("no_magic",1);
    setup();
} 
void reset()
{
        object *inv;
        object endtable, item, item1;
        string book;
        string *books = ({"hanmeiforce", "dodgebook", "axsteps", "qiuzhisword"});
        ::reset();
        book = books[random(4)];
        endtable = present("endtable", this_object());
        inv = all_inventory(endtable);
        if( !sizeof(inv)) 
        {
                item = new(__DIR__"obj/forcebook");
                item->move(endtable);
                item = new(__DIR__"obj/movebook");
                item->move(endtable);
           item = new(__DIR__"obj/swordbook");
                item->move(endtable);
                item1 = new(__DIR__"obj/" + book);
                item1->move(endtable);
        }
        ::reset();
} 
/*
int invalid_leave(object player) {
        object *inv;
        int i;
        inv = all_inventory(player);
        for (i=0;i<sizeof(inv);i++ )
        {               
                if (objectp(inv[i]) && inv[i]->query("marks/banned"))
                {
                        return notify_fail("you cannot take book out of here \n");
                }
        }
        return 0;
}
*/   
