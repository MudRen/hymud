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
	set_name("[1;35m����֮��[2;37;0m", ({ "bad sword", "sword" }));
	set_weight(2852);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
��֮��[2;37;0m����һ���ɷǳ���Ӳ��[32m��ͭ[2;37;0m�Ƴɣ������������Ǯ��[1;35m��֮��[2;37;0m��
�ۺ�����[32m����ϸ��[2;37;0m �������ǳ�����������[32mˮ׼����[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[33m�ܸ�[2;37;0m [1;37m��[2;37;0m:[31m����[2;37;0m [37m��[2;37;0m:[34mϸ��[2;37;0m 
���滹����һЩ���֣�
����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�Ʊ���[2;37;0m ������һЩ�� [1;32m�м�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "spray");
		set("ownername", "�Ʊ���");
		set("value", 2000);
		set("weapon_prop/intelligence",72);
		set("weapon_prop/strength",72);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",72);
		set("weapon_prop/constitution",72);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 72);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 72);
    set("weapon_prop/jingli", 72);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",2);
    set("wtypeJ",9);
    set("wtypeK",9);
    set("wtypeL",9);
    

                set("skill", ([
                        "name": "parry",
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
	
	init_sword(647);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";