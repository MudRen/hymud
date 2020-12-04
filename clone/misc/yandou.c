#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});
void create()
{
        set_name(HIY"九五至尊"NOR, ({ "yandou" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这是一包很普通的九五至尊，里面装满了烟草，如果你喜欢可以抽（ｓｍｏｋｅ）几口。\n");
                set("value", 3000);
		set("armor_prop/intelligence",5);
		set("armor_prop/karey",5);
		set("armor_prop/percao",5);
		set("armor_prop/strength",5);
		set("armor_prop/dexerity",5);
		set("armor_prop/constitution",5);
		set("armor_prop/armor", 200); 
		set("armor_prop/damage",200);
		set("no_get",1);
		set("no_drop",1);
		set("rigidity",100);
		set("material", "steel");
		set("no_put",1);
		set("no_get",1);
		set("no_drop",1);
		set("no_give",1);
		set("no_steal",1);  
		    set("no_get",1);
	  set("no_put",1);
	  set("no_give",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		
		              
 set("wtypeA",3);
    set("wtypeB",3);
    set("wtypeC",3);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",3);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 100,              
                ]) );		
		//set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);
                set("material", "steel");
                set("wield_msg", "$N从怀里磨磨蹭蹭地掏出一包$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n收了起来。\n");
        }
        ::init_sword(680);
}  
void init(){
        if (userp(environment(this_object())))
                add_action("do_smoke","smoke");
        return;
}   
int do_smoke(){
		object me;
        me=this_player();

        message_vision(WHT"$N拿出一根九五至尊，唆着嘴狂抽几下，长长吐了口气，活神仙呀！！\n"NOR,this_player());
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚用过.\n");
        //this_player()->apply_condition("cough",random(10)+10);
	me->set("jing",me->query("max_jing"));
	me->set("eff_jing",me->query("max_jing"));
	me->set("qi",me->query("max_qi"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("neili",me->query("max_neili"));

	me->apply_condition("zdizi_busy",3);
	message_vision(GRN "\n$N的气血和精力，顺间得到了恢复！\n" NOR, me);	
        return 1;
}  

#include "/obj/ritem/weaponzy.h";
int query_autoload() { return 1; }