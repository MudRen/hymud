 inherit ROOM;
#include <ansi.h>
#include <command.h> 
void create()
{
        set("short", "�µ�");
        set("long", @LONG
�������ǰ��һ��С������ˮ�����Թ⣬������Ĵ������ߵ�ϸɳ��
͸���峺�ĺ�ˮ������Կ�����ˮ����Ϸ����Ϻ����������ˮ���������
��ˮ�ݡ�������һЩ��С�Ĺ�ľ����ľ�Ժ���һ���������Ƶ�Σ�£�����
�Ը߲����ʵĸо���
LONG
        );
        set("item_desc", ([
                "ϸɳ": "��׵�ɳ̲��¶��һ�Ǿɲ���\n",
                "Σ��": "�±���ͬ������һ���㣬�������ˣ������ݲ�����̧ͷ����\n����Լ�ɼ�������ͻ��һ���ɫ��ɽʯ��\n",
        ]) );
        set("objects", ([ 
                __DIR__"obj/sand" : 1,
        ]));
        set("outdoors","fengyun");
        set("coor/x",200);
        set("coor/y",-30);
        set("coor/z",20);
        setup();
} 
void init()
{
        add_action("do_climb", "climb");
        add_action("do_dive", "dive");
} 
void reset()
{
        object          *inv;
        object          con, item;
        int             i; 
        ::reset();
        con = present("sand", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/oilbag");
                item->move(con);
        }
} 
int do_climb(string arg)
{
        object  me;
        int     mlvl; 
        if(!arg || (arg != "Σ��" && arg != "up" && arg != "cliff")) {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        me = this_player();
        mlvl = (int)me->query_skill("dodge");
        if(mlvl < 70) 
                message_vision(HIY "\n$N����������ȥ�����˲��������ɣ�ֻ�����ֽŷ������»�����ȥ��\n"NOR, me);
        else {
                message_vision(HIY "\n$NС�������������ȥ�������������������ڡ�\n"NOR, me);
                me->move(__DIR__"whiterock");
        }
        return 1;
} 
int do_dive()
{
        object *inv,me;
        object bottom;
        int i;
        string  objname; 
        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                objname = (string)inv[i]->query("name");
                if( objname != "��Ƥ��" && objname != "«έ")
                        DROP_CMD->do_drop(me, inv[i]);
        }
        message_vision("$N�ѹ��������·���һ�����������ˮ�У�\n",me);
        bottom = load_object(__DIR__"bottom1");
        if(bottom) me->move(bottom);
        return 1;
}   
