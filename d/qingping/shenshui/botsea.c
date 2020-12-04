 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
������һƬ���������������������������������뵽���յ�ҹ�ա�����������
һ���׵�ɳ�����鳤��ɺ���Ľ�ʯɢ����ɳ���ϣ��᳤�ĺ���΢΢��ҡ���ţ�ż
���м���С���ι���ȴ���ܴ���������ļš�
LONG
        );
        set("exits", ([
                "up" : __DIR__"midsea", 
        ]) );
        set("item_desc",([
                "sand" : "��׵�ϸɳ���ں��ף������ƺ���ʲô������\n", 
                "ɳ" : "��׵�ϸɳ���ں��ף������ƺ���ʲô������\n", 
        ]) );
        set("no_fly",1);
        set("count",1);
        set("coor/x",190);
        set("coor/y",12310);
        set("coor/z",-70);
        setup();
} 
void init(){
        object me;
        me = this_player();
        if(userp(me) && !me->query_temp("apply/use_under_water")){
                call_out("airing", 5, this_player());
        }
        add_action("do_search", "search");
        if(!random(20)){
                call_out("see_light", 3, this_player());
        }
} 
int do_search(){
        object me;
        me = this_player();
    
        if(me->is_busy()) {
                return notify_fail("������æ��\n");
        }
        if(me->is_fighting()){
                return notify_fail("�����ȴ�����˵�ɡ�\n");
        }
        message_vision("$N�ں�����ϸ��Ѱ��\n", me);
        me->start_busy(2);
        call_out("result", 4, me);
        return 1;
} 
int result(object me) {
        object seashell;
        if(environment(me) == this_object()){
                if(!random(5) && !present("sea shell", this_object()) && query("count")) {
                        tell_object(me, "\n���Ȼ����һ���󺣰���\n");
                        message_vision(HIC"\n��ֻ����һ˿��ӨӨ�Ĺ����ǰһ�����š�\n"NOR, me);
                        message_vision("����΢΢����һ�£����ǽ��������ˡ�\n", me);
                        seashell = new(__DIR__"obj/seashell");
                        seashell->move(this_object());
                        set("count",0);
                        return 1;
                }
                tell_object(me, "��ʲôҲû�з��֡�\n");
        }
    return 1;
} 
int see_light(object me){
        if(environment(me) == this_object()) {
                message("vision", HIC"\nһ����ӨӨ��΢��һ�����š�\n"NOR, environment(me));
        }
} 
int valid_leave(string dir){
        object me;
        me = this_player();
        if(dir == "up" && me->query_temp("marks/ˮʱ")) {
                me->delete_temp("marks/ˮʱ");
        }
        message_vision("$N���˵���������ȥ��\n", me);
           return 1;
} 
int airing(object ob)
{
        int i, htime, ntime;
    
        if(ob->query_temp("apply/use_under_water")) {
                return 1;
        }
        if(environment(ob) == this_object()){
                htime = (int)ob->query_str() + (int)ob->query_kar();
        if(!(ntime = (int)ob->query_temp("marks/ˮʱ"))) {  
                ntime = 5;
        } else {
                ntime = ntime + 5;
        }
        ob->set_temp("marks/ˮʱ", ntime);
        if( ntime > htime ) {
            ob->die();
            ob->set_temp("marks/ˮʱ", 0);
        }
        else if( ntime > (htime - 15) )
            message_vision(HIR "$N�Ѿ���óɰ����״̬���ٲ����Ͽ��ˮ���ͻ�����������\n"NOR, ob);
        else if( ntime > (htime - 30) )
            message_vision(HIR "$N�Ѿ���������࣬�����֮���ٲ���ˮ�����»�����������\n"NOR, ob);
        else 
            message_vision(HIB "$N�����ؿ�Խ��Խ�ƣ������ˮ���Ѵ����˺ܾá�\n"NOR, ob);
        
        call_out("airing",5, ob);
    }
    return 1;
}  
void reset(){
        ::reset();
        set("count",1);
}   
