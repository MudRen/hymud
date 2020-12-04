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
	set_name("[1;37m������[2;37;0m", ({ "taiji dagger", "dagger" }));
	set_weight(270);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", @LONG
[1;33m̫���ߣ��޼�����������֮ĸҲ����֮��֣���֮��ϡ��޹��������������졣
�˸�����ν֮�ߣ���˳�˱�ν֮ճ��������Ӧ���������档��仯��ˣ���
��Ϊһ�ᣡ
[2;37;0m����һ֧���ޱȼ�Ӳ��[31m��������[2;37;0m�Ƴɣ������������Ǯ��[1;33m̫��֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;33m������ƥ[2;37;0m��������
������˼����ŷ��ţ�
[1;36m��[2;37;0m:[1;32mħ��[2;37;0m [1;33m��[2;37;0m:[1;31m����[2;37;0m [36mľ[2;37;0m:[1;31m��Ԫ[2;37;0m [32mˮ[2;37;0m:[1;35m����[2;37;0m [31m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
����:[1;31m����[2;37;0m ����:[35m��׼[2;37;0m ����:[31m����[2;37;0m ����:[1;36m����[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[31m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "��ͼһ��");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",48);
		set("weapon_prop/percao",56);
		set("weapon_prop/dexerity",56);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 48);
    set("weapon_prop/parry", 56);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 55);
    
    set("weapon_prop/neili", 68);
    set("weapon_prop/qi", 74);
    set("weapon_prop/jing", 46);
    set("weapon_prop/jingli", 46);
    set("weapon_prop/damage", 64);

    set("wtypeA",14);
    set("wtypeB",13);
    set("wtypeC",11);
    set("wtypeD",6);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	//set_amount(99);
	init_dagger(976);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";