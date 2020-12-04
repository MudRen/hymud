#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;37m����֮����[2;37;0m", ({ "bagua armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;37m�����С��ݡ����������ˡ����š�������������������������֮�𣬴��������򣬼����������һ��
[2;37;0m����һ�����ޱȼ�Ӳ��[31m��������[2;37;0m����[37m���˿[2;37;0m�Ƴɣ�������������Ǯ��[1;37m����֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[1;33m��ʥ[2;37;0m [33m��[2;37;0m:[1;31m����[2;37;0m [1;35m��[2;37;0m:[1;31m��˫[2;37;0m 
[1;37m��[2;37;0m:[1;31m��Ԫ[2;37;0m [1;34m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[31m����[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[31m����[2;37;0m ����:[34mϸ��[2;37;0m ����:[31m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mʷ�ٷ���[2;37;0m ������һЩ�� [1;32m�޷�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "ʷ�ٷ���");
		set("value", 25000);
		set("armor_prop/intelligence",16);
		set("armor_prop/strength",16);
		set("armor_prop/karey",24);
		set("armor_prop/percao",16);
		set("armor_prop/dexerity",16);
		set("armor_prop/constitution",8);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 16);


    set("armor_prop/armor", 204);
    set("armor_prop/defense", 8);
    
    set("armor_prop/neili", 32);
    set("armor_prop/qi", 61);
    set("armor_prop/jing", 28);
    set("armor_prop/jingli", 28);
    set("armor_prop/damage", 112);

    set("wtypeA",0);
    set("wtypeB",10);
    set("wtypeC",0);
    set("wtypeD",4);
    set("wtypeE",14);
    set("wtypeF",12);
    set("wtypeG",13);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";