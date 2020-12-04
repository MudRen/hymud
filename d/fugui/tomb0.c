 inherit ROOM;
#include <ansi.h>; 
void create()
{
    object con, bot; 
        set("short", "�ķ�"); 
        set("long", @LONG
������������һ����ڣ�����ܾ�����ľ���ڵ��⼸���������գ�ʱ��ʱ����
˸�ż���Ʈ�������Ĺ�𣬺��紵��ʱ��һ������ɫ�������ƺ��ӻ�ڣ������Զ
����ʱ����һ����Ұ���İ����������ǹ�ޡ�������ϸ�Ŀ�����ͷ�ƺ����˶�����
�ڷ���һ����ɫ�Ĵ�ƿ��
LONG); 
        set("get_ciping",1);
        set("be_ambushed",1);
        set("type","street");
        set("outdoors", "fugui");
        set("exits",([
                "east":__DIR__"tomb2",
        ]) );
        set("objects", ([
                __DIR__"npc/hong" : 1,
                __DIR__"npc/cui" : 1,
                __DIR__"obj/fentou": 1,
        ]) ); 
        set("coor/x",-650);
        set("coor/y",170);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_get","get");
} 
void reset()
{
        object *inv;
        object item, fentou;
        ::reset();
        set("be_ambushed",1);
        fentou = present("fentou", this_object());
   inv = all_inventory(fentou);
        if( !sizeof(inv)) 
        {
                item = new(__DIR__"obj/ciping");
                item->move(fentou);
        }
} 
int do_get(string arg)
{
        object chi, wu;
        object me;
        int kee,sen,gin;
        string what,where;
        me = this_player();
        if(!arg) return 0;
        if(sscanf(arg,"%s from %s",what, where) !=2) 
                return 0;
        if((where == "fentou" || where == "��ͷ" ))
        {
                if (query("be_ambushed"))
                {
                        kee = (int) me->query("max_qi")/4;
                        gin = (int) me->query("max_jing")/4;
                        sen = (int) me->query("max_jing")/4;
                        message_vision(HIR"$N���������ͷ��׼���ö�����\n\nͻȻ....................\n\n"NOR, me);
                        message_vision(HIR"һ˫��ͻȻ�ӷ�Ĺ���������������$Nϥ���ϵġ�����Ѩ������һ˫\n��ͬʱ�ӻ�ѩ�������������������ź�������$N�����ס�\n\n"NOR, me);
                        if (me->query("combat_exp")<400000) {
                                me->die();
                        message_vision(HIR"��˫��������Ϣ���������˷�Ĺ�\n"NOR, me);
                                return 1;
                        }
                        me->receive_wound("qi", kee);
                        me->receive_wound("jing", gin);
                        me->receive_wound("jing", sen);
                        me->apply_condition("redsnake",5+random(10));
                        set("be_ambushed",0);
                        me->start_busy(2);
                        chi = new(__DIR__"npc/chi");
                        wu = new(__DIR__"npc/wu");
                        chi->move(this_object());
                   wu->move(this_object());
                        chi->kill_ob(this_player());
                        wu->kill_ob(this_player());
                        return 1;     
                }
                return 0;
        }
        return 0;
}      
