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
        set("coor/x",-1060);
        set("coor/y",-10);
        set("coor/z",-10);
        setup();
} 
void init(){    
        
        object ob;
        if( interactive( ob = this_player())) {
                ob->set_temp("sinking", 1);
                remove_call_out("sinking");
                call_out("sinking", 1, ob);
        }
} 
int sinking(object ob){
        int i, j;
        int damage;
  
        if(ob && environment(ob) == this_object()){
                j = ob->query_temp("sinking");
                message_vision(HIW"$N������ɳ��������һЩ����", ob);
                message_vision("$N�����ھ����п��˳�������\n"NOR, ob);
                ob->set_temp("sinking", j + 1);
                damage = random(5)+5;
                i =  (int)ob->query("qi");
           ob->set("qi",(int) i - damage);
                if (j == 5) {
                        message_vision(HIG"\nͻȻ�䣬��ɳ�»������ƶ���һ�¡�¶����һ�����µĶ��ڡ�\n"NOR,ob);
                        set("exits/down", __DIR__"chensha1");
                        call_out("close_path", random(6)+10, ob);
                }
                if( environment(ob) == this_object()){
                        call_out("sinking",random(5)+10, ob);   
                }
        }
        else 
        return 1;
} 
int close_path(object ob){
        if( query("exits/down") ) {
        message("vision","\n��ɳ�����»�������Խ��ԽС���ܿ�Ͳ����ˡ�\n", this_object() );
        delete("exits/down");
    }
}  
int valid_leave(object who,string dir)
{
        object me;
     
        me = this_player();
        if(dir=="down"){
                if(me->query_str() > 20) {
                message("vision",me->name() + "һ���ģ���������������ȥ... " , this_object(), me);
                return 1;
        } else {
                return notify_fail("�����ƺ�����ף���������ԥ��������������ɳ�����ꡣ \n");
        }
    }
    return 0;
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
