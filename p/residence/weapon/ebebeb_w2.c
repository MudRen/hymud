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
	set_name("[1;37m��Ӱ��[2;37;0m", ({ "good sword", "sword" }));
	set_weight(2522);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
��ĸ֮��[2;37;0m����һ�����ޱȼ�Ӳ��[31m����ʯ[2;37;0m�Ƴɣ������������Ǯ��[1;37m��ĸ֮��[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ޱȷ���������[1;36mն����ħ[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;33m��[2;37;0m:[35m��׼[2;37;0m [36mľ[2;37;0m:[33m�ܸ�[2;37;0m [33m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
����:[1;33m��ʥ[2;37;0m ��ʯ:[36m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[36m����[2;37;0m ����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĽ����[2;37;0m ������һЩ�� [1;32mָ��[2;37;0m ���ļ��ɡ�

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
		set("value", 9000);
		set("weapon_prop/intelligence",24);
		set("weapon_prop/strength",24);
		set("weapon_prop/karey",40);
		set("weapon_prop/percao",24);
		set("weapon_prop/dexerity",8);
		set("weapon_prop/constitution",16);
    set("weapon_prop/dodge", 8);
    set("weapon_prop/parry", 14);
    set("weapon_prop/attack", 8);
    set("weapon_prop/armor", 40);
    set("weapon_prop/defense", 16);
    
    set("weapon_prop/neili", 8);
    set("weapon_prop/qi", 36);
    set("weapon_prop/jing", 24);
    set("weapon_prop/jingli", 19);
    set("weapon_prop/damage", 20);

    set("wtypeA",5);
    set("wtypeB",4);
    set("wtypeC",1);
    set("wtypeD",4);
    set("wtypeE",9);
    set("wtypeF",1);
    set("wtypeG",1);
    set("wtypeH",2);
    set("wtypeI",10);
    set("wtypeJ",3);
    set("wtypeK",1);
    set("wtypeL",1);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 10);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(761);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";