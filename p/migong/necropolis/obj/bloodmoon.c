#include <ansi.h>
inherit ITEM; 

void create()
{
        set_name("Ѫ��", ({"blood moon"}) );
        set_weight(300);
        set("no_get", 1);
        set("maze_item",1);
        set("unit", "��");
        set("long", "һ��Ѫ��ɫ��������������зǹ�ֵ���������˺����������ƹ�����\n");
        set("value", 2000);
        setup();
} 

void hurt() {
	object *objs,obj;
	
	if(!environment())
	        return;
	if(!query("owner")) {
                destruct(this_object());
                return;
	}
	objs = all_inventory(environment());
	foreach(obj in objs) {
		if(obj==query("owner") || obj->is_undead()) {
			message_vision(HIC"Ѫ�µĹ⻪����$N���ϣ�$N��þ���ٱ���\n"NOR,obj);
			obj->receive_heal("qi",4000);
			obj->receive_curing("qi",4000);
			obj->receive_heal("jing",2000);
			obj->receive_curing("jing",2000);
			continue;
		}
		if(userp(obj)) {
			message_vision(HIR"Ѫ�µĹ⻪����$N���ϣ�$N���������ڿ��ٵ���ʧ��\n"NOR,obj);
			obj->receive_damage("qi",2000+random(1000),query("owner"));
			obj->receive_damage("jing",1000+random(1000),query("owner"));
			COMBAT_D->report_status(obj);
		}
	}
	call_out("hurt",5);
}
