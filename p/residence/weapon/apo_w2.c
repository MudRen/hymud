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
	set_name("[1;31mɱ����[2;37;0m", ({ "moye blade", "blade" }));
	set_weight(5489);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31mĪа�����ޱȣ��ܿ���ٵأ�������ħ��
[2;37;0m����һ���ɾ��Լ�Ӳ��[1;36m���꺮����[2;37;0m�Ƴɣ���ʮ�������Ǯ��[31mĪа֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m ���������Է���������[1;35m��������[2;37;0m��������
������˼����ŷ��ţ�
[40m��[2;37;0m:[1;31m����[2;37;0m [36mľ[2;37;0m:[1;31m����[2;37;0m [1;35m��[2;37;0m:[1;35m����[2;37;0m 
[1;37m��[2;37;0m:[31m����[2;37;0m [1;34m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[35m��׼[2;37;0m ��ʯ:[1;34m����[2;37;0m ��ʯ:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m 
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
		set("owner", "apo");
		set("ownername", "����");
		set("value", 36000);
		set("weapon_prop/intelligence",36);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 82);
    set("weapon_prop/parry", 51);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 55);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 52);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 59);

    set("wtypeA",0);
    set("wtypeB",14);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",6);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",14);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 23);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_blade(944);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";