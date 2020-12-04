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
	set_name("[1;37mÌ«°×Ö®½£[2;37;0m", ({ "taibai sword", "sword" }));
	set_weight(10675);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;37m
		ÕÔ¿ÍçÏºúÓ§  Îâ¹³ËªÑ©Ã÷		Òø°°ÕÕ°×Âí  ìªí³ÈçÁ÷ĞÇ
		Ê®²½É±Ò»ÈË  Ç§Àï²»ÁôĞĞ		ÊÂÁË·÷ÒÂÈ¥  Éî²ØÉíÓëÃû
		ÏĞ¹ıĞÅÁêÒû  ÍÑ½£Ï¥Ç°ºá		½«ÖË¡õÖìº¥  ³ÖõüÈ°ºîÙø
		Èı±­ÍÂÈ»Åµ  ÎåÓüµ¹ÎªÇá		ÑÛ»¨¶úÈÈáá  ÒâÆøËØÄŞÉú
		¾ÈÕÔ»Ó½ğé³  ºªµ¦ÏÈÕğ¾ª		Ç§Çï¶ş×³Ê¿  ĞúºÕ´óÁº³Ç
		×İËÀÏÀ¹ÇÏã  ²»²ÑÊÀÉÏÓ¢		Ë­ÄÜÊé¸óÏÂ  °×Ê×Ì«Ğş¾­
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®Ò»½ïÈıÁ½ÎåÇ®µÄ[1;37mÌ«°×Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31mÌìÏÂÎŞË«[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;33m½ğ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31mÎŞË«[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m»ÙÌì[2;37;0m ÌìĞş:[34mÏ¸Ëé[2;37;0m ×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¿Æ±È[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÈ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "¿Æ±È");
		set("value", 25000);
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",32);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",29);
    set("weapon_prop/dodge", 40);
    set("weapon_prop/parry", 28);
    set("weapon_prop/attack", 48);
    set("weapon_prop/armor", 40);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 51);
    set("weapon_prop/qi", 30);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 48);
    set("weapon_prop/damage", 0);

    set("wtypeA",14);
    set("wtypeB",5);
    set("wtypeC",6);
    set("wtypeD",8);
    set("wtypeE",8);
    set("wtypeF",12);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",5);
    set("wtypeJ",5);
    set("wtypeK",4);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1352);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";