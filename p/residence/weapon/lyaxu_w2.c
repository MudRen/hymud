// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[1;32mÇ§¾û°ô[2;37;0m", ({ "general club", "club" }));
	set_weight(5265);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
×Ïê–Ö®¹÷[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[33mÈíÌú[2;37;0mÖÆ³É£¬ÖØÊ®½ïÎåÁ½ÈıÇ®µÄ[1;32m×Ïê–Ö®¹÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;36mÍêÃÀ[2;37;0m [36mÄ¾[2;37;0m:[1;36mÍêÃÀ[2;37;0m [32mË®[2;37;0m:[34mÏ¸Ëé[2;37;0m [1;35m·ç[2;37;0m:[35m±ê×¼[2;37;0m 
[1;34mµç[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[32m´Ö²Ú[2;37;0m ÖÜÌì:[36m²»´í[2;37;0m ³¤Éú:[36m²»´í[2;37;0m ²»ÀÏ:[36m²»´í[2;37;0m ÍşÁ¦:[33mÒ»°ã[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÆÆÀÃÕ¾[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕĞ¼Ü[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "ÆÆÀÃÕ¾");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 15);
    set("weapon_prop/qi", 11);
    set("weapon_prop/jing", 11);
    set("weapon_prop/jingli", 11);
    set("weapon_prop/damage", 9);

    set("wtypeA",7);
    set("wtypeB",7);
    set("wtypeC",2);
    set("wtypeD",0);
    set("wtypeE",3);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_club(260);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";