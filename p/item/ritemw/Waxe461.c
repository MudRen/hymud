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
	set_name("[31m��Ȫ֮��[2;37;0m", ({ "longquan axe", "axe" }));
	set_weight(9612);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m��Ȫ�˼伫Ʒ������������
[2;37;0m����һ�����ޱȼ�Ӳ��[1;37m����[2;37;0m�Ƴɣ���ʮ�Ž������Ǯ��[31m��Ȫ֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;31m������˫[2;37;0m��������
������˼����ŷ��ţ�
[32mˮ[2;37;0m:[1;33m��ʥ[2;37;0m [1;37m��[2;37;0m:[31m����[2;37;0m [37m��[2;37;0m:[1;35m����[2;37;0m [40m��[2;37;0m:[31m����[2;37;0m [1;31mħ[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ��Դ:[33m�ܸ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 


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
		set("weapon_prop/intelligence",42);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",44);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",42);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 43);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",11);
    set("wtypeJ",6);
    set("wtypeK",0);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "claw",
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
	
	init_axe(1260);
	setup();
}



#include "/obj/ritem/weaponzy.h";