#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", HIW"ѩ����"NOR);
        set("long", @LONG
�±�����һ���˹���̵�ɽ����������û����֪������ΪʲôҪ����ɽ����
��������ϰϰ����ʹ�������ȵ��ļ���ֻҪһ�붴�ڣ����⾡����������ȥ�����
ƺ�������ڣ����Ͽ�������ʯ�ưߵ��ʾ�Ө����ѩ������Ʈ�䡣
LONG
        );
    set("exits", ([ 
                "southwest" : __DIR__"qingke",
        ])); 
        set("objects", ([
                __DIR__"npc/bailong" : 1,
                __DIR__"npc/fang": 1,
        ]) );  
        set("doing_rescue", 0);
    set("indoors", "huashan"); 
    set("coor/x",-576);
    set("coor/y",-68);
    set("coor/z",40);
        setup();
} 
void init(){
        if(this_player()->query("marks/���������")) {
                call_out("save_me", 1, this_player());
        }
        add_action("do_rescue", "rescue");
} 
void save_me(object me){
        object sun, fang;
        sun = present("sun yuanchao", this_object());
        fang = present("fang girl", this_object());
        if(objectp(sun) && objectp(fang) && !query("doing_rescue")) {
                message_vision("\n$Nԭ����Ȼ���˵����񿴵�$n��Ȼһ�����̶�����һ˿���۸��ӵĹ�â��\n", fang, me);
                message_vision("$N���ܵ�$n��ǰȴ����Զ�����裬ֻ�ýе��������ң���\n��Թ�����������������̡�\n", fang, me);
                tell_object(me, "���������塡�������\n", me);
                set("doing_rescue", 1);
           call_out("reluctant", 40, me);
        }
} 
int do_rescue(string arg){
        object me;
        me = this_player();
        if(!arg || (arg != "yes" && arg != "no")){
                return 0;
        }       
        if(arg == "yes" && query("doing_rescue")){
                remove_call_out("reluctant");
        me->command("kill sun yuanchao");
        } else if(arg == "no"){
                remove_call_out("reluctant");
                message("vision", me->name() + "�۹���һɨ�������Ϻ��ޱ��顣\n", environment(me), me);
                tell_object(me, "������²��ؼ������ǲ�Ҫ���ֵĺá�\n");
                me->set("marks/��������", 1);
        }
        return 1;
} 
void reluctant(object me){
        if(!interactive(me) || environment(me) != environment(this_object())){
                return 0;
        }
        message_vision("$N�����г�����ʧ����ĬĬ�ĵ�����ͷ��\n", this_object());
        me->set("marks/��������", 1);
                 return ;
} 
void check_rescue(object me){
        object fang;
        fang = present("fang girl", this_object());
        if(objectp(fang)){
                call_out("rescued", 2, me);
        }
} 
void rescued(object me){
        object fang;
        if(!interactive(me) || environment(me) != this_object()) {
                return ;
        }
        fang = present("fang girl", this_object());
   if(objectp(fang)){
                if(me->query("age") < 25){
                        message_vision("$N����$nǳǳһЦ��һ����Ʒ�����գ�����л��λ��������֮������\n", fang, me);
                        message_vision("�Ա���Ůת��������ȥ���ߵ����ڣ���Ů���������������תͷ����$Nһ�ۡ�\n", me);
                        me->set("marks/�ټ������", 1);
                } else {
                        message_vision("$N��������л��λ��������֮������\n", fang, me);
                        message_vision("�Ա���Ůת��������ȥ��\n", me);
                }
                if(!me->query("imbue/fang_girl")){
                        me->start_busy(3);
                        call_out("imbue_event", 2, me);
                }
                destruct(fang);
                         }
} 
void imbue_event(object me){
        object weapon, ob, *inv, obj;
        string prop;
        int i; 
        if(!interactive(me) || environment(me) != this_object()) {
                return ;
        } 
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }
        if(!objectp(weapon)){
                if(!objectp(obj)) {
                        message_vision(HIW"\nһ���ɫ��ӫ��Ӷ�������Ʈ�䣬���綬����ѩ����\n"NOR, me);
                } else {
                        message_vision(HIW"\nһ���ɫ��ӫ��Ӷ�������Ʈ����$N��" + obj->name() +
                                   HIW"�ϣ�ת�ۼ�����ȥ��\n"NOR, me);
                }
        }else{
                message_vision(HIW"\nһ���ɫ��ӫ��Ӷ�������Ʈ����$N��" + weapon->name() + HIW"�ϡ�����\n"NOR,
                                me);
                message_vision(HIW"ӫ���һ�Ӵ�" + weapon->name()+ HIW"һ��ҫ�۵Ĺ�âէ��Ѹ��һ���ֻع�ƽ����\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                }
                if(me->query("����B")){
                        weapon->add(prop+"courage", 2);
                        weapon->add(prop+"composure", 2);
                } else {
                        weapon->add(prop+"courage", 2);
                        weapon->add(prop+"personality", 2);
                }
                weapon->save();
                me->set("imbue/fang_girl", 1);
                me->save();
                return;
        }
        me->set("imbue/fang_girl", 2);
        me->save();
        return;
}      
