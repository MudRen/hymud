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
	set_name("[31m����֮��[2;37;0m��", ({ "chungou axe", "axe" }));
	set_weight(2252);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m������˧֮������֮�ܻӾ����򣬿˵���ʤ��
[2;37;0m����һ���ɼ����Ӳ��[1;37m����[2;37;0m�Ƴɣ����Ľ�������Ǯ��[31m����֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������������������[1;36mն����ħ[2;37;0m��������
������˼����ŷ��ţ�
[31m��[2;37;0m:[1;34m����[2;37;0m [33m��[2;37;0m:[1;35m����[2;37;0m [1;35m��[2;37;0m:[1;36m����[2;37;0m 
[1;37m��[2;37;0m:[1;34m����[2;37;0m [40m��[2;37;0m:[1;34m����[2;37;0m [1;36m��[2;37;0m:[1;31m����[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ��Դ:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m ��ʯ:[1;34m����[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",46);
		set("weapon_prop/karey",37);
		set("weapon_prop/percao",42);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",41);
    set("weapon_prop/dodge", 87);
    set("weapon_prop/parry", 49);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",11);
    set("wtypeF",7);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",8);
    set("wtypeK",15);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 21);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_axe(656);
	setup();
}



#include "/obj/ritem/weaponzy.h";