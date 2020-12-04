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
	set_name("[1;37m��Ӱ��[2;37;0m", ({ "general blade", "blade" }));
	set_weight(5135);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
��˼֮��[2;37;0m����һ���ɷǳ���Ӳ��[1;32m��ʯ[2;37;0m�Ƴɣ���ʮ�������Ǯ��[1;37m��˼֮��[2;37;0m��
�ۺ�����[31m��������[2;37;0m �������ǳ�����������[35m�������[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[34mϸ��[2;37;0m [36mľ[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[1;34m����[2;37;0m 
[1;34m��[2;37;0m:[35m��׼[2;37;0m 
���滹����һЩ���֣�
����:[32m�ֲ�[2;37;0m ����:[32m����[2;37;0m ��Դ:[33mһ��[2;37;0m 
��Ԩ:[33mһ��[2;37;0m ����:[32m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĽ����[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "Ľ����");
		set("value", 2000);
		set("weapon_prop/intelligence",3);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",6);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",8);
		set("weapon_prop/constitution",4);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 24);
    set("weapon_prop/jingli", 24);
    set("weapon_prop/damage", 0);

    set("wtypeA",2);
    set("wtypeB",8);
    set("wtypeC",0);
    set("wtypeD",1);
    set("wtypeE",2);
    set("wtypeF",8);
    set("wtypeG",2);
    set("wtypeH",5);
    set("wtypeI",3);
    set("wtypeJ",0);
    set("wtypeK",7);
    set("wtypeL",2);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_blade(397);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";