 inherit ROOM;
#include <room.h>
void create()
{
        set("short", "�ص�");
        set("long", @LONG
�ص����ԣ�ÿ��ʮ��������һյʯ�ƣ�������ʮ�������ǵ�����ʯ�ţ��ʹ���
���೤����
LONG
        );
        set("exits",([
                "up" :__DIR__"stone1",
                "west" : __DIR__"stone3",
        
        ]) );
        create_door("west","����ʯ��","east",DOOR_CLOSED); 
        set("coor/x",2090);
        set("coor/y",-220);
        set("coor/z",-20);
        setup();
}
void init()
{
        add_action("do_bomb","bomb");
}
int do_bomb(string arg)
{
        object  me, *inv, exp, nroom;
        int     i; 
        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
                if( (int) inv[i]->query("explosive") ) exp = inv[i];
        if( !exp)  return 0;
        message_vision("$N��ȼ�����е�"+exp->name()+"������
ֻ����һ��������죢�䣢�����ڱ�ը�����󶴣�\n", me, exp);
        destruct(exp);
        nroom = find_object(__DIR__"rock0");
        if(!objectp(nroom))
                nroom = load_object(__DIR__"rock0");
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                inv[i]->unconcious();
            }
        }
        me->move(nroom);
        return 1;
}  
