// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[1;35m����֮��[2;37;0m", ({ "good blade", "blade" }));
	set_weight(2829);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
����֮��[2;37;0m����һ���ɾ��Լ�Ӳ��[33m����[2;37;0m�Ƴɣ������������Ǯ��[1;35m����֮��[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m ���������Է���������[1;36mն����ħ[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[31m����[2;37;0m [1;35m��[2;37;0m:[1;34m����[2;37;0m 
[1;34m��[2;37;0m:[1;33m��ʥ[2;37;0m [37m��[2;37;0m:[32m�ֲ�[2;37;0m [40m��[2;37;0m:[1;34m����[2;37;0m [1;31mħ[2;37;0m:[33m�ܸ�[2;37;0m 
���滹����һЩ���֣�
����:[1;35m����[2;37;0m ����:[36m����[2;37;0m ����:[36m����[2;37;0m ����:[36m����[2;37;0m ��ʯ:[36m����[2;37;0m ����:[36m����[2;37;0m 
����:[34mϸ��[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 9000);
		set("weapon_prop/intelligence",12);
		set("weapon_prop/strength",14);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",11);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 12);
    set("weapon_prop/attack", 16);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 23);
    set("weapon_prop/jingli", 23);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",10);
    set("wtypeI",3);
    set("wtypeJ",8);
    set("wtypeK",0);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 11);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_blade(577);
	setup();
}



#include "/obj/ritem/weaponzy.h";