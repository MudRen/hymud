 // Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h> 
inherit ROOM;
int do_sanddrop(object me, object obj);
void create()
{
        set("short", "��ɳ");
        set("long", @LONG
���Ѿ�������ɳ֮�У�����û��һ�������ĵط�����һ����������ȥ������
������(pull)��һ�ѣ�������뿪������±ȵ��컹�ѡ����ƺ��Ѿ������ڰ��޳�
���������֡�
LONG
        ); 
        set("NONPC",1); 
        set("coor/x",-1040);
        set("coor/y",-20);
        set("coor/z",-10);
        setup();
} 
void init()
{       object ob;
        if( interactive( ob = this_player()))
        {
        remove_call_out("sinking");
        call_out("sinking", 1, ob);
        }
} 
int sinking(object ob) 
{
        int i;
        int damage;
        if( ob && environment(ob) == this_object())
        {
        message_vision(HIW"$N������ɳ��������һЩ����", ob);
        message_vision("$N�����ھ����п��˳�������\n"NOR, ob);
        damage = random(5)+2;
        i =  (int)ob->query("qi");
        ob->set("qi",(int) i - damage);
        if( environment(ob) == this_object())
   call_out("sinking",random(5)+7, ob);    
        }
        else 
        return 1;
}
int do_quit()
{
        object me, *inv;
        int i;
        me = this_player();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        do_sanddrop(me, inv[i]);
                }
}
int do_sanddrop(object me, object obj)
{
        mixed no_drop;
        if( no_drop = obj->query("no_drop") )
                return 0;
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
                else {
                        message_vision( sprintf("$N����һ%s$n��\n",     obj->query("unit")),
                                me, obj );
                        me->save();
                        if( !obj->query("value") && !obj->value() ) {
                                write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;  
}       
