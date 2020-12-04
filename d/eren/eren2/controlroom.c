#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long",  @LONG
��������ȴ�и��ܹŹֵĵط����Ǿ�����ô��һ���������ֻ��һ
�����ӣ������ʲô��û���ˡ���������Ҳ��ֵúܣ��������Ȳ�����ͨ
��̫ʦ�Σ�Ҳ����Ů�ӹ���г�������һ�֡��������ӿ��������Ǹ��ܴ�
�ܴ�����ӣ�ֻ�����м䰼��ȥһ�飬������ȥ�󣬾ͺ���Ƕ�������ˡ�
�����ϵ���һյͭ�ƣ��������յú�����
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"guardroom",
        ]));
        set("objects", ([
                __DIR__"npc/star_chick" : 1,
                __DIR__"npc/star_c1" : 1,
                __DIR__"npc/star_c2" : 1,
                __DIR__"npc/star_c3" : 1,
                __DIR__"npc/star_c4" : 1,
        ]) );
        set("item_desc", ([
        "����" : "���ӵķ���(arm)�ܿ���Ҳ������ӣ����Դ�����(break)��\n",
        "chair" : "���ӵķ���(arm)�ܿ���Ҳ������ӣ����Դ�����(break)��\n",
        "ͭ��" : "��ͭ��(lamp)Ҳ��Щ�Ź֣������ƺ�����ת����turn����\n",
        "lamp" : "��ͭ��(lamp)Ҳ��Щ�Ź֣������ƺ�����ת����turn����\n",
    ])); 
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("elevator",1);
        set("thread",1);
        setup();
        
} 
void init(){
        add_action("do_open", "break");
        add_action("do_turn", "turn");
} 
int do_open(string arg){
        object me, guard;    
        object *inv;
        int i;
        
        me = this_player();
        if(!arg || (arg != "arm" && arg != "����")) {
                return 0;
        }
        inv = all_inventory(this_object());
        for (i=1;i<sizeof(inv);i++) {
                if (inv[i]->query("dungeon_npc")=="eren2")
                {
                if (me->short()!="�׹����(Xianguo)")
                        return notify_fail(inv[i]->query("name")+"�ȵ�����͵͵���������ʲô����\n");
                }
        }
        if(query("elevator") || query("thread")) {
                message_vision(HIW"$NС������ؽ����ӷ�������ĸ���������������������һ����ֻ
�����񡱵�һ�����漴���ں���һ�����ǵ������������־���������\n"NOR,this_player());
                this_object()->set("elevator",0);
                this_object()->set("thread",0);
                me->start_busy(2);
                if (me->short()=="�׹����(Xianguo)") 
                for (i=1;i<sizeof(inv);i++) {
                        if (inv[i]->query("dungeon_npc")=="eren2") {
                                message_vision(CYN"$N����һ����У�ץ��ϸ��\n"NOR,me);
                                inv[i]->kill_ob(me);
                                }
                }                                                       
        } else {
                tell_object(me,HIW"��С����������������ӷ��֣�ʲô����Ҳû�С�\n"NOR);
                me->start_busy(2);
                }
        return 1;
} 
int do_turn(string arg){
        object me, guard, trap_room;    
        object *inv;
        int i;
        
        me = this_player();
        if(!arg || (arg != "lamp" && arg != "ͭ��")) {
                return 0;
        }
        inv = all_inventory(this_object());
        for (i=1;i<sizeof(inv);i++) {
                if (inv[i]->query("dungeon_npc")=="eren2")
                return notify_fail(inv[i]->query("name")+"�ȵ�����͵͵���������ʲô����\n");
        }
        message_vision(HIW"$NС������ؽ�ͭ����ת��ת�˼��¡�\n"NOR,this_player());
        message_vision(HIR"�ذ壬����Ȼ���˿�����¶���˸��ض���$Nһ�������Խ��˶��\n"NOR,this_player());
        trap_room = find_object(__DIR__"underjail1");
        if(!objectp(trap_room))
                 trap_room = load_object(__DIR__"underjail1");
        this_player()->move(trap_room);
        this_player()->unconcious();
        return 1;
} 
void reset()
{
        ::reset();
        set("elevator",1);
        set("thread",1);
        
}     
