// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit HAMMER;

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
	set_name("[31m̫��֮��[2;37;0m��", ({ "taie hammer", "hammer" }));
	set_weight(15828);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m̫������֮������֮�ܺ������£�Ī�в��ӣ�
[2;37;0m����һ���ɾ��Լ�Ӳ��[1;37m����[2;37;0m�Ƴɣ�����ʮһ��������Ǯ��[31m̫��֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m ���������Է���������[1;31m������˫[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[31m����[2;37;0m [32mˮ[2;37;0m:[1;31m��Ԫ[2;37;0m [31m��[2;37;0m:[31m����[2;37;0m [33m��[2;37;0m:[1;35m����[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m ��Ԩ:[33m�ܸ�[2;37;0m ��ʯ:[1;34m����[2;37;0m ����:[35m��׼[2;37;0m 
����:[1;34m����[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[1;32mħ��[2;37;0m 

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
		set("weapon_prop/intelligence",49);
		set("weapon_prop/strength",45);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",47);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 89);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 57);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 82);
    set("weapon_prop/qi", 45);
    set("weapon_prop/jing", 93);
    set("weapon_prop/jingli", 93);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",6);
    set("wtypeC",13);
    set("wtypeD",6);
    set("wtypeE",11);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_hammer(1250);
	setup();
}



#include "/obj/ritem/weaponzy.h";