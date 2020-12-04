// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
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
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;36m�׺�[2;37;0m", ({ "bad sword", "sword" }));
	set_weight(2466);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
��֮��[2;37;0m����һ�����൱��Ӳ��[32m��ͭ[2;37;0m�Ƴɣ����Ľ������Ǯ��[1;36m��֮��[2;37;0m��
�ۺ�����[32m����ϸ��[2;37;0m �������൱����������[36m��С[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[35m��׼[2;37;0m [1;34m��[2;37;0m:[33m�ܸ�[2;37;0m [37m��[2;37;0m:[32m�ֲ�[2;37;0m 
���滹����һЩ���֣�
����:[33m�ܸ�[2;37;0m ��ʯ:[32m����[2;37;0m ����:[33mһ��[2;37;0m 
����:[32m����[2;37;0m ����:[32m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�����һ��[2;37;0m ������һЩ�� [1;32m�ȷ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "faxone");
		set("ownername", "�����һ��");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 4);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 7);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 2);
    set("weapon_prop/jingli", 2);
    set("weapon_prop/damage", 5);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",4);
    set("wtypeI",3);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 4);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(73);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";