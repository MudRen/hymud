// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;34m����֮����[2;37;0m", ({ "general throwing", "throwing" }));
	set_weight(192);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", @LONG
����֮����[2;37;0m����һ֧���ޱȼ�Ӳ��[33m����[2;37;0m�Ƴɣ������������Ǯ��[1;34m����֮����[2;37;0m��
�ۺ�����[31m��������[2;37;0m �������ޱȷ���������[32mˮ׼����[2;37;0m��������
������˼����ŷ��ţ�
[1;35m��[2;37;0m:[35m��׼[2;37;0m 
[1;37m��[2;37;0m:[34mϸ��[2;37;0m [40m��[2;37;0m:[1;36m����[2;37;0m 
���滹����һЩ���֣�
����:[35m��׼[2;37;0m ����:[33mһ��[2;37;0m ����:[32m����[2;37;0m ��Ԩ:[33mһ��[2;37;0m ����:[33mһ��[2;37;0m 
����:[36m����[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",9);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",2);
		set("weapon_prop/dexerity",7);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 7);
    set("weapon_prop/defense", 19);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",5);
    set("wtypeG",2);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",7);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 5);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	set_amount(1);
	init_throwing(187);
	setup();
}



#include "/obj/ritem/weaponzy.h";