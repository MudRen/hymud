// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[1;32m����[2;37;0m", ({ "zhendian throwing", "throwing" }));
	set_weight(386);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", @LONG
[37m���֮����[2;37;0m����һ֧�ɼ����Ӳ��[1;33m����[2;37;0m�Ƴɣ������������Ǯ��[37m���֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������������������[31m�����ױ�[2;37;0m��������
������˼����ŷ��ţ�
[1;36m��[2;37;0m:[33m�ܸ�[2;37;0m [32mˮ[2;37;0m:[1;35m����[2;37;0m [33m��[2;37;0m:[1;36m����[2;37;0m [1;35m��[2;37;0m:[1;35m����[2;37;0m 

���滹����һЩ���֣�
����:[1;31m��˫[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m ����:[34mϸ��[2;37;0m ����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĪ����[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wslts");
		set("ownername", "Ī����");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 46);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 45);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 55);
    set("weapon_prop/qi", 20);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 26);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",11);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",11);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
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
	set_amount(99);
	init_throwing(557);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";