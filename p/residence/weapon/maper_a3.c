#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;33m¹ÂĞÇÕ½ÔÂîø[2;37;0m", ({ "taibai cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;37m
		ÕÔ¿ÍçÏºúÓ§  Îâ¹³ËªÑ©Ã÷		Òø°°ÕÕ°×Âí  ìªí³ÈçÁ÷ĞÇ
		Ê®²½É±Ò»ÈË  Ç§Àï²»ÁôĞĞ		ÊÂÁË·÷ÒÂÈ¥  Éî²ØÉíÓëÃû
		ÏĞ¹ıĞÅÁêÒû  ÍÑ½£Ï¥Ç°ºá		½«ÖË¡õÖìº¥  ³ÖõüÈ°ºîÙø
		Èı±­ÍÂÈ»Åµ  ÎåÓüµ¹ÎªÇá		ÑÛ»¨¶úÈÈáá  ÒâÆøËØÄŞÉú
		¾ÈÕÔ»Ó½ğé³  ºªµ¦ÏÈÕğ¾ª		Ç§Çï¶ş×³Ê¿  ĞúºÕ´óÁº³Ç
		×İËÀÏÀ¹ÇÏã  ²»²ÑÊÀÉÏÓ¢		Ë­ÄÜÊé¸óÏÂ  °×Ê×Ì«Ğş¾­
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÊ®¶ş½ïËÄÁ½ÆßÇ®µÄ[1;37mÌ«°×Ö®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;31m¿ªÔª[2;37;0m [36mÄ¾[2;37;0m:[1;31m´´ÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÌìÓî:[34mÏ¸Ëé[2;37;0m ¸£Ô´:[34mÏ¸Ëé[2;37;0m 
ÇÉÖÆ:[35m±ê×¼[2;37;0m 
×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÖÜÌì:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mµØÍ¼Ò»ºÅ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÄÚ¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "µØÍ¼Ò»ºÅ");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",56);
		set("armor_prop/percao",64);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 1888);
    set("armor_prop/defense", 64);
    
    set("armor_prop/neili", 64);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 64);
    set("armor_prop/damage", 1253);

    set("wtypeA",6);
    set("wtypeB",14);
    set("wtypeC",6);
    set("wtypeD",8);
    set("wtypeE",7);
    set("wtypeF",7);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",13);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";