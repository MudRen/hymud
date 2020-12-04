// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[1;31m֮ͭذ��[2;37;0m", ({ "bad dagger", "dagger" }));
	set_weight(5669);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
֮ͭذ��[2;37;0m����һ����ʮ�ּ�Ӳ��[32m��ͭ[2;37;0m�Ƴɣ���ʮһ��������Ǯ��[1;31m֮ͭذ��[2;37;0m��
�ۺ�����[32m����ϸ��[2;37;0m ������ʮ�ַ���������[32mˮ׼����[2;37;0m��������
������˼����ŷ��ţ�
[32mˮ[2;37;0m:[36m����[2;37;0m [40m��[2;37;0m:[36m����[2;37;0m 
���滹����һЩ���֣�
����:[35m��׼[2;37;0m ����:[32m����[2;37;0m 
����:[33mһ��[2;37;0m 
����:[32m����[2;37;0m ����:[32m����[2;37;0m 

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
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 9);
    set("weapon_prop/armor", 5);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 2);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 3);
    set("weapon_prop/jingli", 3);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",1);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",1);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 5);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_dagger(279);
	setup();
}



#include "/obj/ritem/weaponzy.h";