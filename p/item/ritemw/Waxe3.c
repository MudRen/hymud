// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit AXE;

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
	set_name("[37m��֮��[2;37;0m", ({ "bad axe", "axe" }));
	set_weight(14397);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
��֮��[2;37;0m����һ���ɷǳ���Ӳ��[32m��ͭ[2;37;0m�Ƴɣ��ض�ʮ�˽�������Ǯ��[37m��֮��[2;37;0m��
�ۺ�����[32m����ϸ��[2;37;0m �������ǳ�����������[35m�������[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[36m����[2;37;0m [40m��[2;37;0m:[32m�ֲ�[2;37;0m [1;36m��[2;37;0m:[32m�ֲ�[2;37;0m 
���滹����һЩ���֣�
����:[34mϸ��[2;37;0m ����:[33mһ��[2;37;0m ��Ԩ:[33mһ��[2;37;0m ����:[32m����[2;37;0m 
����:[33mһ��[2;37;0m 

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
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",7);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",9);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 2);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 6);
    set("weapon_prop/jingli", 6);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",1);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",3);
    set("wtypeK",3);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 2);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_axe(331);
	setup();
}



#include "/obj/ritem/weaponzy.h";