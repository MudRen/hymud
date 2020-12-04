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
	set_name("[31m����֮ذ��[2;37;0m", ({ "juque dagger", "dagger" }));
	set_weight(7332);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m���ڼ�Ӳ�ޱȣ��ܿ���ٵأ�������ħ��
[2;37;0m����һ�����ޱȼ�Ӳ��[1;37m����[2;37;0m�Ƴɣ���ʮ�Ľ�������Ǯ��[31m����֮ذ��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;31m��Ԫ����[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[1;34m����[2;37;0m [32mˮ[2;37;0m:[1;32mħ��[2;37;0m [1;35m��[2;37;0m:[1;34m����[2;37;0m 

���滹����һЩ���֣�
����:[1;33m����[2;37;0m ��Ԩ:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m 

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
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",41);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 50);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 46);
    set("weapon_prop/qi", 52);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 50);

    set("wtypeA",0);
    set("wtypeB",8);
    set("wtypeC",9);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "club",
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
	
	init_dagger(1368);
	setup();
}



#include "/obj/ritem/weaponzy.h";