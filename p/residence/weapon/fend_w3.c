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
	set_name("[32m�ɺ�֮ذ��[2;37;0m", ({ "songhe dagger", "dagger" }));
	set_weight(9547);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[32m�ɺ�֮ذ��[2;37;0m����һ�����ޱȼ�Ӳ��[1;33m����[2;37;0m�Ƴɣ���ʮ�Ž�������Ǯ��[32m�ɺ�֮ذ��[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȷ���������[1;33m������ƥ[2;37;0m��������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[1;34m����[2;37;0m [36mľ[2;37;0m:[1;32mħ��[2;37;0m [31m��[2;37;0m:[31m����[2;37;0m [33m��[2;37;0m:[1;32mħ��[2;37;0m [1;34m��[2;37;0m:[33m�ܸ�[2;37;0m 
���滹����һЩ���֣�
����:[1;31m��˫[2;37;0m ����:[36m����[2;37;0m 
����:[32m�ֲ�[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fend");
		set("ownername", "����");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 44);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 33);
    set("weapon_prop/armor", 16);
    set("weapon_prop/defense", 36);
    
    set("weapon_prop/neili", 34);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",9);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",4);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_dagger(905);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";