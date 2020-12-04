 // corpse.c
#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("����", ({ "delve" }) );
        set("long", "һ�����ӣ������ƺ�������������ʲô������������\n");
        set("unit", "��" );
        set_max_encumbrance(800000000);
        set("no_get",1);
        
} 
int is_container() { return 1; } 
void init()
{
        add_action("do_bury","bury");
} 
int do_bury()
{       object me; 
        me=this_player();
        if (me->query("libie/���_β��") && 
                        (present("yang's corpse", this_object()) && present("lu's corpse", this_object())))
        {
                message_vision("$Nһ��һ��Ľ��������˿��У�����򸾵�ʬ��������������\n",me);
                tell_object(me,HIY"���㽫���һ�������������ʱ����ʹ�У����ƺ�������ʲô����ȴ��˵��������\n"NOR);
                if (!me->query("marks/���")) {
                        me->set("marks/���",1);
                        me->add("potential",100);
                        me->add("score",100);
                        me->add("combat_exp",10000);
                }       
                if(!me->query("imbue/libie")){
                        me->start_busy(3);
                        call_out("imbue_event", 2, me);                         
                }
        } else {
                message_vision("$N�û���������ƽ��\n",me);
                destruct(this_object());
        }
        return 1;
}
        
int imbue_event(object me){
        object weapon, ob, *inv, obj;
        string prop;
        int i; 
        if(!interactive(me) || environment(me) != environment(this_object())) {
                return 0;
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
                        message_vision(YEL"\nһ�����紵��������һ���ɫ��ɳ����\n"NOR, me);
                } else {
                        message_vision(YEL"\nһ�����紵��������һ���ɫ��ɳ����$N��" + obj->name() +
                                        HIR"�ϣ�ת�ۼ��������һ�㱡���Ļ�ɳ��\n"NOR, me);
                }
        }else{
                if(weapon->query("equipped") == "wielded") {
                        tell_object(me, "վ����ƽ�������ԣ������г����п������ɵ��ɿ����е�"+weapon->name()+"��\n");
                        weapon->unequip();
                }
                message_vision(YEL"\nһ�����紵��������һ���ɫ��ɳ����$N��" + weapon->name() + YEL"�ϣ�ת�ۼ��������һ�㱡���Ļ�ɳ��\n"NOR,
                                me);
                message_vision(HIY"\nһ��ҫ�۵Ļ�ɫ��â��" + weapon->name() + 
HIY"����������ɳ��Ȼ����" + weapon->name()+HIY"��ɼ��ˡ�\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
           weapon->add(prop+"courage", 5);
                weapon->add(prop+"composure", 5);
                weapon->save();
                me->set("imbue/libie", 1);
                me->save();
                destruct(this_object());
                return 1;
        }
        me->set("imbue/libie", 2);
        me->save();
        destruct(this_object());
}              
